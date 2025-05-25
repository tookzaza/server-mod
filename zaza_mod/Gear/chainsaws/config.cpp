class CfgPatches
{
	class RA_Chainsaws
	{
		units[]=
		{
			"Chainsaw_Green",
			"Chainsaw_Red",
			"Chainsaw_Yellow",
			"Chainsaw_White",
			"Chainsaw_Black",
			"Chainsaw_Blood"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Weapons_Melee_Powered"
		};
	};
};
class CfgVehicles
{
	class Switchable_Base;
	class Chainsaw: Switchable_Base
	{
		displayName="Chainsaw";
		descriptionShort="A portable chainsaw used for cutting trees, or ripping victims apart...";
		isMeleeWeapon=1;
		stackedUnit="ml";
		attachments[]={};
		itemSize[]={10,3};
		quantityBar=1;
		varQuantityDestroyOnMin=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=5000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\melee\powered\Data\chainsaw.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\melee\powered\Data\chainsaw.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\melee\powered\Data\chainsaw_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\melee\powered\Data\chainsaw_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\melee\powered\Data\chainsaw_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyStorageMax=5000;
			energyAtSpawn=5000;
			convertEnergyToQuantity=1;
			energyUsagePerSecond=3;
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeChainsaw";
				range=1.6;
			};
			class Heavy
			{
				ammo="MeleeChainsaw";
				range=1.6;
			};
			class Sprint
			{
				ammo="MeleeChainsaw";
				range=2.2;
			};
			class Default_SwitchedOn
			{
				ammo="MeleeChainsaw";
				range=1.6;
			};
			class Heavy_SwitchedOn
			{
				ammo="MeleeChainsaw";
				range=1.6;
			};
			class Sprint_SwitchedOn
			{
				ammo="MeleeChainsaw";
				range=2.2;
			};
		};
	};
	class Chainsaw_Green: Chainsaw
	{
		scope=2;
		displayName="Green Chainsaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"zaza_mod\Gear\chainsaws\data\chainsaw_co_green.paa"
		};
	};
	class Chainsaw_Red: Chainsaw
	{
		scope=2;
		displayName="Red Chainsaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"zaza_mod\Gear\chainsaws\data\chainsaw_co_red.paa"
		};
	};
	class Chainsaw_Yellow: Chainsaw
	{
		scope=2;
		displayName="Yellow Chainsaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"zaza_mod\Gear\chainsaws\data\chainsaw_co_yellow.paa"
		};
	};
	class Chainsaw_White: Chainsaw
	{
		scope=2;
		displayName="White Chainsaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"zaza_mod\Gear\chainsaws\data\chainsaw_co_white.paa"
		};
	};
	class Chainsaw_Black: Chainsaw
	{
		scope=2;
		displayName="Black Chainsaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"zaza_mod\Gear\chainsaws\data\chainsaw_co_black.paa"
		};
	};
	class Chainsaw_Blood: Chainsaw
	{
		scope=2;
		displayName="Bloody Chainsaw";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"zaza_mod\Gear\chainsaws\data\chainsaw_co_blood.paa"
		};
	};
};
class CfgSoundShaders
{
	class baseCharacter_SoundShader
	{
	};
	class powerChainsawON_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"zaza_mod\Gear\chainsaws\data\ChainsawON",
				1
			}
		};
		volume=0.5;
		range=50;
	};
	class powerChainsawOFF_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"zaza_mod\Gear\chainsaws\data\ChainsawOFF",
				1
			}
		};
		volume=0.80000001;
		range=30;
	};
	class powerChainsawLOOP_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"zaza_mod\Gear\chainsaws\data\ChainsawIDLE",
				1
			}
		};
		volume=0.80000001;
		range=30;
	};
	class powerChainsawRev_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"zaza_mod\Gear\chainsaws\data\ChainsawRUNNING",
				1
			}
		};
		volume=1.2;
		range=30;
	};
};
class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class powerChainsawON_Soundset: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"powerChainsawON_Soundshader"
		};
	};
	class powerChainsawOFF_Soundset: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"powerChainsawOFF_Soundshader"
		};
	};
	class powerChainsawLOOP_Soundset: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"powerChainsawLOOP_Soundshader"
		};
	};
	class powerChainsawRev_Soundset: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"powerChainsawRev_Soundshader"
		};
	};
};
class CfgSounds
{
	class default
	{
		name="";
		titles[]={};
	};
	class ChainsawONAction_1: default
	{
		sound[]=
		{
			"zaza_mod\Gear\chainsaws\data\ChainsawAction",
			3,
			1,
			30
		};
	};
};
class CfgActionSounds
{
	class ChainsawONAction
	{
		sounds[]=
		{
			"ChainsawONAction_1"
		};
	};
};
