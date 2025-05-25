modded class Chainsaw
{
	static const int LOGS_FROM_TREES = 2;
	static const int PLANKS_FROM_TREES = 5;
	
	static const string			LOOP_SOUND = "powerChainsawLOOP_Soundset";
	static const string			STOP_SOUND = "powerChainsawOFF_Soundset";
	
	protected EffectSound 		m_EngineLoop;
	protected EffectSound 		m_EngineStop;
	protected EffectSound 		m_ActionLoopSound;

	protected ref Timer 		m_SoundLoopStartTimer;
	protected ref Effect 		m_Smoke;

	void ~Chainsaw()
	{
		delete m_Smoke;
		delete m_SoundLoopStartTimer;
	}
	
	void StartLoopSound()
	{
		if (!g_Game.IsDedicatedServer()) {
			PlaySoundSetLoop(m_EngineLoop, LOOP_SOUND, 0, 0);
			m_Smoke = new EffGeneratorSmoke();
			SEffectManager.PlayOnObject(m_Smoke, this, vector.Zero, "90 0 0");
		}
	}
	
	override void OnWorkStart()
	{
		super.OnWorkStart();
		
		if (!g_Game.IsDedicatedServer()) {
			if (!m_SoundLoopStartTimer) {
				m_SoundLoopStartTimer = new Timer(CALL_CATEGORY_GAMEPLAY);
			}
			
			if (!m_SoundLoopStartTimer.IsRunning()) {
				m_SoundLoopStartTimer.Run(0, this, "StartLoopSound", NULL, false);
			}
		}
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		
		if (!g_Game.IsDedicatedServer()) {
			PlaySoundSet(m_EngineStop, STOP_SOUND, 0, 0);
			StopSoundSet(m_EngineLoop);
			
			delete m_Smoke;
		}
	}

	void StartActionSound()
	{
		if (!g_Game.IsDedicatedServer()) {
			m_ActionLoopSound = SEffectManager.PlaySound("powerChainsawRev_Soundset", GetPosition(), 0.5, 0.5, true);
		}
	}

	void StopActionSound()
	{
		if (!g_Game.IsDedicatedServer()) {
			m_ActionLoopSound.SoundStop();
		}
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if (!super.CanPutInCargo(parent)) {
			return false;
		}
		
		return (!GetCompEM().IsSwitchedOn());
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionChainsawPlanks);
		AddAction(ActionChainsawLogs);
		AddAction(ActionChainsawTree);
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
		RemoveAction(ActionDestroyPart);
	}
}

class Chainsaw_Orange: Chainsaw {}
class Chainsaw_Green: Chainsaw {}
class Chainsaw_Red: Chainsaw {}
class Chainsaw_Yellow: Chainsaw {}
class Chainsaw_White: Chainsaw {}
class Chainsaw_Black: Chainsaw {}
class Chainsaw_Blood: Chainsaw {}