class CfgPatches
{
	class VCMDamageTweeks
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Weapons_Projectiles",
			"DZ_Weapons_Firearms"
		};
		ammo[]=
		{
			"MeleeDamage",
			"MeleeChainsaw",
			"MeleeChainsaw_Heavy"
		};
	};
};
class CfgAmmo
{
	class Bullet_Base;
	class MeleeDamage: Bullet_Base
	{
	};
	class MeleeChainsaw: MeleeDamage
	{
		affectSkeleton=1;
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=1;
			class Health
			{
				damage=35;
			};
			class Blood
			{
				damage=250;
			};
			class Shock
			{
				damage=0;
			};
			additionAnimalMeleeMultiplier=2;
		};
	};
	class MeleeChainsaw_Heavy: MeleeChainsaw
	{
		affectSkeleton=1;
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=1;
			class Health
			{
				damage=45;
			};
			class Blood
			{
				damage=300;
			};
			class Shock
			{
				damage=0;
			};
			additionAnimalMeleeMultiplier=2;
		};
	};
};
