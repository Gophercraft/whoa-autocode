// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_SPELLVISUALKIT_REC_HPP
#define DB_SPELLVISUALKIT_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct SpellVisualKitRec {
	static constexpr uint32_t columnCount = 38;
	static constexpr uint32_t rowSize = 152;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_StartAnimID;
	int32_t m_AnimID;
	int32_t m_HeadEffect;
	int32_t m_ChestEffect;
	int32_t m_BaseEffect;
	int32_t m_LeftHandEffect;
	int32_t m_RightHandEffect;
	int32_t m_BreathEffect;
	int32_t m_LeftWeaponEffect;
	int32_t m_RightWeaponEffect;
	int32_t m_SpecialEffect[3];
	int32_t m_WorldEffect;
	int32_t m_SoundID;
	int32_t m_ShakeID;
	int32_t m_CharProc[4];
	float m_CharParamZero[4];
	float m_CharParamOne[4];
	float m_CharParamTwo[4];
	float m_CharParamThree[4];
	int32_t m_Flags;

	static const char* GetFilename() {
		return "DBFilesClient\\SpellVisualKit.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_StartAnimID, sizeof(this->m_StartAnimID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AnimID, sizeof(this->m_AnimID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_HeadEffect, sizeof(this->m_HeadEffect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ChestEffect, sizeof(this->m_ChestEffect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_BaseEffect, sizeof(this->m_BaseEffect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_LeftHandEffect, sizeof(this->m_LeftHandEffect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RightHandEffect, sizeof(this->m_RightHandEffect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_BreathEffect, sizeof(this->m_BreathEffect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_LeftWeaponEffect, sizeof(this->m_LeftWeaponEffect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RightWeaponEffect, sizeof(this->m_RightWeaponEffect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpecialEffect[0], sizeof(m_SpecialEffect[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpecialEffect[1], sizeof(m_SpecialEffect[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpecialEffect[2], sizeof(m_SpecialEffect[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_WorldEffect, sizeof(this->m_WorldEffect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SoundID, sizeof(this->m_SoundID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ShakeID, sizeof(this->m_ShakeID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharProc[0], sizeof(m_CharProc[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharProc[1], sizeof(m_CharProc[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharProc[2], sizeof(m_CharProc[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharProc[3], sizeof(m_CharProc[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamZero[0], sizeof(m_CharParamZero[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamZero[1], sizeof(m_CharParamZero[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamZero[2], sizeof(m_CharParamZero[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamZero[3], sizeof(m_CharParamZero[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamOne[0], sizeof(m_CharParamOne[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamOne[1], sizeof(m_CharParamOne[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamOne[2], sizeof(m_CharParamOne[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamOne[3], sizeof(m_CharParamOne[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamTwo[0], sizeof(m_CharParamTwo[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamTwo[1], sizeof(m_CharParamTwo[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamTwo[2], sizeof(m_CharParamTwo[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamTwo[3], sizeof(m_CharParamTwo[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamThree[0], sizeof(m_CharParamThree[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamThree[1], sizeof(m_CharParamThree[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamThree[2], sizeof(m_CharParamThree[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CharParamThree[3], sizeof(m_CharParamThree[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Flags, sizeof(this->m_Flags), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		return true;
	}
};

#endif