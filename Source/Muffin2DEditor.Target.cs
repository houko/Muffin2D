// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Muffin2DEditorTarget : TargetRules
{
    public Muffin2DEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.AddRange(new string[] {"Muffin2D"});
    }
}