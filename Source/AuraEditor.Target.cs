// Copyright TwinFaerie, for use on online course by Druid Mechanic only

using UnrealBuildTool;
using System.Collections.Generic;

public class AuraEditorTarget : TargetRules
{
	public AuraEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "Aura" } );
	}
}
