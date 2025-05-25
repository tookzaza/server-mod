class ActionChainsawLogsCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(3.0);
	}
}


class ActionChainsawLogs: ActionContinuousBase
{
	void ActionChainsawLogs()
	{
		m_CallbackClass = ActionChainsawLogsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_WRING;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_FullBody = true;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTTree(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}
	
	override string GetText()
	{
		return "Saw Log";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return (target.GetObject().Type() == WoodenLog && item.HasEnergyManager() && item.GetCompEM().IsWorking());
	}

	override void OnStartClient(ActionData action_data)
	{
		super.OnStartClient(action_data);

		if (action_data.m_MainItem.IsInherited(Chainsaw)) {
			Chainsaw chainsaw = Chainsaw.Cast(action_data.m_MainItem);
			chainsaw.StartActionSound();	
		}
	}

	override void OnEndClient(ActionData action_data)	
	{
		super.OnEndClient(action_data);

		if (action_data.m_MainItem.IsInherited(Chainsaw)) {
			Chainsaw chainsaw = Chainsaw.Cast(action_data.m_MainItem);
			chainsaw.StopActionSound();		
		}
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		MiscGameplayFunctions.AddEntityToGroundPos("WoodenPlank", action_data.m_Player.GetPosition(), Chainsaw.PLANKS_FROM_TREES);
		
		WoodenLog ent = WoodenLog.Cast(action_data.m_Target.GetObject());
		if (ent) {
			ent.AddQuantity(-1);
		}
	}
}