// Create by QianMo

using UnrealBuildTool;
using System.Collections.Generic;

public class BattleTankEditorTarget : TargetRules
{
	public BattleTankEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "BattleTank" } );
	}
}
