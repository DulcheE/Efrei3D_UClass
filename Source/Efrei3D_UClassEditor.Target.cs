// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class Efrei3D_UClassEditorTarget : TargetRules
{
	public Efrei3D_UClassEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Efrei3D_UClass" } );
	}
}
