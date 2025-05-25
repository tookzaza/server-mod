class ActionChainsawTreeCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(5.0);
	}
}


class ActionChainsawTree: ActionContinuousBase
{
	void ActionChainsawTree()
	{
		m_CallbackClass = ActionChainsawTreeCB;
		// m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_HACKBUSH; - Not bad, funny but not bad
		// m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CUTBARK; - Not bad, one handed but saw action looks good
		// m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_RESTRAINTARGET; Not bad - too much movements and obvious that its what it is
		// m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CLEANWOUNDSTARGET; Not bad..

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
		return "Saw Tree";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return (target.GetObject().IsTree() && target.GetObject().IsCuttable() && item.HasEnergyManager() && item.GetCompEM().IsWorking());
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

		ItemBase planks = ItemBase.Cast(g_Game.CreateObject("WoodenPlank",action_data.m_Player.GetPosition(), false));
		planks.SetQuantity(Chainsaw.PLANKS_FROM_TREES);
		for (int i = 0; i < Chainsaw.LOGS_FROM_TREES; i++) {
			g_Game.CreateObject("WoodenLog", action_data.m_Player.GetPosition(), false);
		}
				
		if (action_data.m_Target.GetObject()) {
			action_data.m_Target.GetObject().SetAllowDamage(true);
			action_data.m_Target.GetObject().SetHealth("", "", 0.0);
		}
	}
}