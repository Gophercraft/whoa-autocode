// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_SPELL_REC_HPP
#define DB_SPELL_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct SpellRec {
	static constexpr uint32_t columnCount = 234;
	static constexpr uint32_t rowSize = 936;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_Category;
	int32_t m_DispelType;
	int32_t m_Mechanic;
	int32_t m_Attributes;
	int32_t m_AttributesEx;
	int32_t m_AttributesExB;
	int32_t m_AttributesExC;
	int32_t m_AttributesExD;
	int32_t m_AttributesExE;
	int32_t m_AttributesExF;
	int32_t m_AttributesExG;
	int32_t m_ShapeshiftMask[2];
	int32_t m_ShapeshiftExclude[2];
	int32_t m_Targets;
	int32_t m_TargetCreatureType;
	int32_t m_RequiresSpellFocus;
	int32_t m_FacingCasterFlags;
	int32_t m_CasterAuraState;
	int32_t m_TargetAuraState;
	int32_t m_ExcludeCasterAuraState;
	int32_t m_ExcludeTargetAuraState;
	int32_t m_CasterAuraSpell;
	int32_t m_TargetAuraSpell;
	int32_t m_ExcludeCasterAuraSpell;
	int32_t m_ExcludeTargetAuraSpell;
	int32_t m_CastingTimeIndex;
	int32_t m_RecoveryTime;
	int32_t m_CategoryRecoveryTime;
	int32_t m_InterruptFlags;
	int32_t m_AuraInterruptFlags;
	int32_t m_ChannelInterruptFlags;
	int32_t m_ProcTypeMask;
	int32_t m_ProcChance;
	int32_t m_ProcCharges;
	int32_t m_MaxLevel;
	int32_t m_BaseLevel;
	int32_t m_SpellLevel;
	int32_t m_DurationIndex;
	int32_t m_PowerType;
	int32_t m_ManaCost;
	int32_t m_ManaCostPerLevel;
	int32_t m_ManaPerSecond;
	int32_t m_ManaPerSecondPerLevel;
	int32_t m_RangeIndex;
	float m_Speed;
	int32_t m_ModalNextSpell;
	int32_t m_CumulativeAura;
	int32_t m_Totem[2];
	int32_t m_Reagent[8];
	int32_t m_ReagentCount[8];
	int32_t m_EquippedItemClass;
	int32_t m_EquippedItemSubclass;
	int32_t m_EquippedItemInvTypes;
	int32_t m_Effect[3];
	int32_t m_EffectDieSides[3];
	float m_EffectRealPointsPerLevel[3];
	int32_t m_EffectBasePoints[3];
	int32_t m_EffectMechanic[3];
	int32_t m_ImplicitTargetA[3];
	int32_t m_ImplicitTargetB[3];
	int32_t m_EffectRadiusIndex[3];
	int32_t m_EffectAura[3];
	int32_t m_EffectAuraPeriod[3];
	float m_EffectAmplitude[3];
	int32_t m_EffectChainTargets[3];
	int32_t m_EffectItemType[3];
	int32_t m_EffectMiscValue[3];
	int32_t m_EffectMiscValueB[3];
	int32_t m_EffectTriggerSpell[3];
	float m_EffectPointsPerCombo[3];
	int32_t m_EffectSpellClassMaskA[3];
	int32_t m_EffectSpellClassMaskB[3];
	int32_t m_EffectSpellClassMaskC[3];
	int32_t m_SpellVisualID[2];
	int32_t m_SpellIconID;
	int32_t m_ActiveIconID;
	int32_t m_SpellPriority;
	const char* m_Name_lang;
	const char* m_NameSubtext_lang;
	const char* m_Description_lang;
	const char* m_AuraDescription_lang;
	int32_t m_ManaCostPct;
	int32_t m_StartRecoveryCategory;
	int32_t m_StartRecoveryTime;
	int32_t m_MaxTargetLevel;
	int32_t m_SpellClassSet;
	int32_t m_SpellClassMask[3];
	int32_t m_MaxTargets;
	int32_t m_DefenseType;
	int32_t m_PreventionType;
	int32_t m_StanceBarOrder;
	float m_EffectChainAmplitude[3];
	int32_t m_MinFactionID;
	int32_t m_MinReputation;
	int32_t m_RequiredAuraVision;
	int32_t m_RequiredTotemCategoryID[2];
	int32_t m_RequiredAreasID;
	int32_t m_SchoolMask;
	int32_t m_RuneCostID;
	int32_t m_SpellMissileID;
	int32_t m_PowerDisplayID;
	float m_EffectBonusCoefficient[3];
	int32_t m_DescriptionVariablesID;
	int32_t m_Difficulty;

	static const char* GetFilename() {
		return "DBFilesClient\\Spell.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t Name_langOfs[16];
		uint32_t Name_langMask;
		uint32_t NameSubtext_langOfs[16];
		uint32_t NameSubtext_langMask;
		uint32_t Description_langOfs[16];
		uint32_t Description_langMask;
		uint32_t AuraDescription_langOfs[16];
		uint32_t AuraDescription_langMask;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Category, sizeof(this->m_Category), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_DispelType, sizeof(this->m_DispelType), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Mechanic, sizeof(this->m_Mechanic), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Attributes, sizeof(this->m_Attributes), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AttributesEx, sizeof(this->m_AttributesEx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AttributesExB, sizeof(this->m_AttributesExB), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AttributesExC, sizeof(this->m_AttributesExC), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AttributesExD, sizeof(this->m_AttributesExD), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AttributesExE, sizeof(this->m_AttributesExE), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AttributesExF, sizeof(this->m_AttributesExF), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AttributesExG, sizeof(this->m_AttributesExG), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ShapeshiftMask[0], sizeof(m_ShapeshiftMask[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ShapeshiftMask[1], sizeof(m_ShapeshiftMask[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ShapeshiftExclude[0], sizeof(m_ShapeshiftExclude[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ShapeshiftExclude[1], sizeof(m_ShapeshiftExclude[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Targets, sizeof(this->m_Targets), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_TargetCreatureType, sizeof(this->m_TargetCreatureType), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RequiresSpellFocus, sizeof(this->m_RequiresSpellFocus), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_FacingCasterFlags, sizeof(this->m_FacingCasterFlags), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CasterAuraState, sizeof(this->m_CasterAuraState), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_TargetAuraState, sizeof(this->m_TargetAuraState), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ExcludeCasterAuraState, sizeof(this->m_ExcludeCasterAuraState), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ExcludeTargetAuraState, sizeof(this->m_ExcludeTargetAuraState), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CasterAuraSpell, sizeof(this->m_CasterAuraSpell), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_TargetAuraSpell, sizeof(this->m_TargetAuraSpell), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ExcludeCasterAuraSpell, sizeof(this->m_ExcludeCasterAuraSpell), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ExcludeTargetAuraSpell, sizeof(this->m_ExcludeTargetAuraSpell), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CastingTimeIndex, sizeof(this->m_CastingTimeIndex), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RecoveryTime, sizeof(this->m_RecoveryTime), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CategoryRecoveryTime, sizeof(this->m_CategoryRecoveryTime), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_InterruptFlags, sizeof(this->m_InterruptFlags), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AuraInterruptFlags, sizeof(this->m_AuraInterruptFlags), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ChannelInterruptFlags, sizeof(this->m_ChannelInterruptFlags), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ProcTypeMask, sizeof(this->m_ProcTypeMask), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ProcChance, sizeof(this->m_ProcChance), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ProcCharges, sizeof(this->m_ProcCharges), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_MaxLevel, sizeof(this->m_MaxLevel), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_BaseLevel, sizeof(this->m_BaseLevel), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellLevel, sizeof(this->m_SpellLevel), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_DurationIndex, sizeof(this->m_DurationIndex), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_PowerType, sizeof(this->m_PowerType), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ManaCost, sizeof(this->m_ManaCost), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ManaCostPerLevel, sizeof(this->m_ManaCostPerLevel), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ManaPerSecond, sizeof(this->m_ManaPerSecond), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ManaPerSecondPerLevel, sizeof(this->m_ManaPerSecondPerLevel), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RangeIndex, sizeof(this->m_RangeIndex), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Speed, sizeof(this->m_Speed), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ModalNextSpell, sizeof(this->m_ModalNextSpell), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CumulativeAura, sizeof(this->m_CumulativeAura), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Totem[0], sizeof(m_Totem[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Totem[1], sizeof(m_Totem[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Reagent[0], sizeof(m_Reagent[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Reagent[1], sizeof(m_Reagent[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Reagent[2], sizeof(m_Reagent[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Reagent[3], sizeof(m_Reagent[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Reagent[4], sizeof(m_Reagent[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Reagent[5], sizeof(m_Reagent[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Reagent[6], sizeof(m_Reagent[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Reagent[7], sizeof(m_Reagent[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ReagentCount[0], sizeof(m_ReagentCount[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ReagentCount[1], sizeof(m_ReagentCount[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ReagentCount[2], sizeof(m_ReagentCount[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ReagentCount[3], sizeof(m_ReagentCount[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ReagentCount[4], sizeof(m_ReagentCount[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ReagentCount[5], sizeof(m_ReagentCount[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ReagentCount[6], sizeof(m_ReagentCount[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ReagentCount[7], sizeof(m_ReagentCount[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EquippedItemClass, sizeof(this->m_EquippedItemClass), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EquippedItemSubclass, sizeof(this->m_EquippedItemSubclass), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EquippedItemInvTypes, sizeof(this->m_EquippedItemInvTypes), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Effect[0], sizeof(m_Effect[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Effect[1], sizeof(m_Effect[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Effect[2], sizeof(m_Effect[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectDieSides[0], sizeof(m_EffectDieSides[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectDieSides[1], sizeof(m_EffectDieSides[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectDieSides[2], sizeof(m_EffectDieSides[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectRealPointsPerLevel[0], sizeof(m_EffectRealPointsPerLevel[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectRealPointsPerLevel[1], sizeof(m_EffectRealPointsPerLevel[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectRealPointsPerLevel[2], sizeof(m_EffectRealPointsPerLevel[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectBasePoints[0], sizeof(m_EffectBasePoints[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectBasePoints[1], sizeof(m_EffectBasePoints[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectBasePoints[2], sizeof(m_EffectBasePoints[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectMechanic[0], sizeof(m_EffectMechanic[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectMechanic[1], sizeof(m_EffectMechanic[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectMechanic[2], sizeof(m_EffectMechanic[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ImplicitTargetA[0], sizeof(m_ImplicitTargetA[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ImplicitTargetA[1], sizeof(m_ImplicitTargetA[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ImplicitTargetA[2], sizeof(m_ImplicitTargetA[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ImplicitTargetB[0], sizeof(m_ImplicitTargetB[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ImplicitTargetB[1], sizeof(m_ImplicitTargetB[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ImplicitTargetB[2], sizeof(m_ImplicitTargetB[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectRadiusIndex[0], sizeof(m_EffectRadiusIndex[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectRadiusIndex[1], sizeof(m_EffectRadiusIndex[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectRadiusIndex[2], sizeof(m_EffectRadiusIndex[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectAura[0], sizeof(m_EffectAura[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectAura[1], sizeof(m_EffectAura[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectAura[2], sizeof(m_EffectAura[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectAuraPeriod[0], sizeof(m_EffectAuraPeriod[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectAuraPeriod[1], sizeof(m_EffectAuraPeriod[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectAuraPeriod[2], sizeof(m_EffectAuraPeriod[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectAmplitude[0], sizeof(m_EffectAmplitude[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectAmplitude[1], sizeof(m_EffectAmplitude[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectAmplitude[2], sizeof(m_EffectAmplitude[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectChainTargets[0], sizeof(m_EffectChainTargets[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectChainTargets[1], sizeof(m_EffectChainTargets[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectChainTargets[2], sizeof(m_EffectChainTargets[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectItemType[0], sizeof(m_EffectItemType[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectItemType[1], sizeof(m_EffectItemType[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectItemType[2], sizeof(m_EffectItemType[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectMiscValue[0], sizeof(m_EffectMiscValue[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectMiscValue[1], sizeof(m_EffectMiscValue[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectMiscValue[2], sizeof(m_EffectMiscValue[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectMiscValueB[0], sizeof(m_EffectMiscValueB[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectMiscValueB[1], sizeof(m_EffectMiscValueB[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectMiscValueB[2], sizeof(m_EffectMiscValueB[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectTriggerSpell[0], sizeof(m_EffectTriggerSpell[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectTriggerSpell[1], sizeof(m_EffectTriggerSpell[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectTriggerSpell[2], sizeof(m_EffectTriggerSpell[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectPointsPerCombo[0], sizeof(m_EffectPointsPerCombo[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectPointsPerCombo[1], sizeof(m_EffectPointsPerCombo[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectPointsPerCombo[2], sizeof(m_EffectPointsPerCombo[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectSpellClassMaskA[0], sizeof(m_EffectSpellClassMaskA[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectSpellClassMaskA[1], sizeof(m_EffectSpellClassMaskA[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectSpellClassMaskA[2], sizeof(m_EffectSpellClassMaskA[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectSpellClassMaskB[0], sizeof(m_EffectSpellClassMaskB[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectSpellClassMaskB[1], sizeof(m_EffectSpellClassMaskB[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectSpellClassMaskB[2], sizeof(m_EffectSpellClassMaskB[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectSpellClassMaskC[0], sizeof(m_EffectSpellClassMaskC[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectSpellClassMaskC[1], sizeof(m_EffectSpellClassMaskC[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectSpellClassMaskC[2], sizeof(m_EffectSpellClassMaskC[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellVisualID[0], sizeof(m_SpellVisualID[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellVisualID[1], sizeof(m_SpellVisualID[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellIconID, sizeof(this->m_SpellIconID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ActiveIconID, sizeof(this->m_ActiveIconID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellPriority, sizeof(this->m_SpellPriority), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameSubtext_langMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Description_langMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &AuraDescription_langMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ManaCostPct, sizeof(this->m_ManaCostPct), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_StartRecoveryCategory, sizeof(this->m_StartRecoveryCategory), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_StartRecoveryTime, sizeof(this->m_StartRecoveryTime), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_MaxTargetLevel, sizeof(this->m_MaxTargetLevel), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellClassSet, sizeof(this->m_SpellClassSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellClassMask[0], sizeof(m_SpellClassMask[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellClassMask[1], sizeof(m_SpellClassMask[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellClassMask[2], sizeof(m_SpellClassMask[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_MaxTargets, sizeof(this->m_MaxTargets), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_DefenseType, sizeof(this->m_DefenseType), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_PreventionType, sizeof(this->m_PreventionType), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_StanceBarOrder, sizeof(this->m_StanceBarOrder), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectChainAmplitude[0], sizeof(m_EffectChainAmplitude[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectChainAmplitude[1], sizeof(m_EffectChainAmplitude[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectChainAmplitude[2], sizeof(m_EffectChainAmplitude[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_MinFactionID, sizeof(this->m_MinFactionID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_MinReputation, sizeof(this->m_MinReputation), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RequiredAuraVision, sizeof(this->m_RequiredAuraVision), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RequiredTotemCategoryID[0], sizeof(m_RequiredTotemCategoryID[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RequiredTotemCategoryID[1], sizeof(m_RequiredTotemCategoryID[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RequiredAreasID, sizeof(this->m_RequiredAreasID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SchoolMask, sizeof(this->m_SchoolMask), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RuneCostID, sizeof(this->m_RuneCostID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellMissileID, sizeof(this->m_SpellMissileID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_PowerDisplayID, sizeof(this->m_PowerDisplayID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectBonusCoefficient[0], sizeof(m_EffectBonusCoefficient[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectBonusCoefficient[1], sizeof(m_EffectBonusCoefficient[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EffectBonusCoefficient[2], sizeof(m_EffectBonusCoefficient[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_DescriptionVariablesID, sizeof(this->m_DescriptionVariablesID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Difficulty, sizeof(this->m_Difficulty), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		if (stringBuffer) {
			this->m_Name_lang = &stringBuffer[Name_langOfs[CURRENT_LANGUAGE]];
			this->m_NameSubtext_lang = &stringBuffer[NameSubtext_langOfs[CURRENT_LANGUAGE]];
			this->m_Description_lang = &stringBuffer[Description_langOfs[CURRENT_LANGUAGE]];
			this->m_AuraDescription_lang = &stringBuffer[AuraDescription_langOfs[CURRENT_LANGUAGE]];
		} else {
			this->m_Name_lang = "";
			this->m_NameSubtext_lang = "";
			this->m_Description_lang = "";
			this->m_AuraDescription_lang = "";
		}

		return true;
	}
};

#endif