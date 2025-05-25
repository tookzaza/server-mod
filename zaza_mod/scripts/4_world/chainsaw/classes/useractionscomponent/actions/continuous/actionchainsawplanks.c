class ActionChainsawPlanksCB : ActionContinuousBaseCB
{	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(1.0);
	}
}


class ActionChainsawPlanks: ActionContinuousBase
{	
	void ActionChainsawPlanks()
	{
		m_CallbackClass = ActionChainsawPlanksCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_WRING;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_FullBody = true;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}

	override string GetText()
	{
		return "Saw Planks";
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{		
		return (item && target.GetObject().IsInherited(PileOfWoodenPlanks) && item.IsInherited(Chainsaw) && item.HasEnergyManager() && item.GetCompEM().IsWorking());
	}

	override void OnStartClient(ActionData action_data)
	{
		super.OnStartClient(action_data);

		if (action_data.m_MainItem.IsInherited(Chainsaw) && !g_Game.IsDedicatedServer()) {
			Chainsaw chainsaw = Chainsaw.Cast(action_data.m_MainItem);
			chainsaw.StartActionSound();
		}
	}

	override void OnEndClient(ActionData action_data)	
	{
		super.OnEndClient(action_data);

		if (action_data.m_MainItem.IsInherited(Chainsaw) && !g_Game.IsDedicatedServer()) {
			Chainsaw chainsaw = Chainsaw.Cast(action_data.m_MainItem);
			chainsaw.StopActionSound();
		}
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		PileOfWoodenPlanks pile_of_planks = PileOfWoodenPlanks.Cast(action_data.m_Target.GetObject());
		pile_of_planks.RemovePlanks(Chainsaw.PLANKS_FROM_TREES);
		
		WoodenPlank planks = WoodenPlank.Cast(g_Game.CreateObjectEx("WoodenPlank", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE) );
		planks.SetQuantity(Chainsaw.PLANKS_FROM_TREES);
		
		if ((planks.GetQuantity() + Chainsaw.PLANKS_FROM_TREES) >= planks.GetQuantityMax()) {
			int remnant = planks.GetQuantity() + Chainsaw.PLANKS_FROM_TREES - planks.GetQuantityMax();
			planks.SetQuantity(planks.GetQuantityMax());
			if (remnant > 0) {
				planks = WoodenPlank.Cast(g_Game.CreateObjectEx("WoodenPlank", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
				planks.SetQuantity(remnant);
			}
		} 
		
		else {
			planks.AddQuantity(Chainsaw.PLANKS_FROM_TREES);
		}
	}
}