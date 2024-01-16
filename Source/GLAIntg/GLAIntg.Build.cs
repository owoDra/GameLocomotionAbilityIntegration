// Copyright (C) 2024 owoDra

using UnrealBuildTool;

public class GLAIntg : ModuleRules
{
	public GLAIntg(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
           new string[]
           {
                ModuleDirectory,
                ModuleDirectory + "/GLAIntg",
           }
       );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "ModularGameplay",
                "GameplayTags",
                "GameplayAbilities",
                "NetCore",
            }
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "GLExt",
                "GFCore",
                "GAExt",
            }
        );

        SetupIrisSupport(Target);
    }
}
