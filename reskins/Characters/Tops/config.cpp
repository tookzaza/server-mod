class CfgPatches
{
	class reskins_Tops
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data", "DZ_Characters", "DZ_Characters_Tops" };
		units[] = { "TShirt_drink" };
	};
};

class CfgVehicles
{
	class TShirt_ColorBase;
	class TShirt_drink : TShirt_ColorBase
	{
		scope = 2;
		displayName = "Tequila Shirt";
		descriptionShort = "A reskinned T-Shirt with a tequila logo.";
		visibilityModifier = 0.85;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] =
		{
			"reskins\Characters\Tops\data\Tequila.paa"
		};
	};
};
