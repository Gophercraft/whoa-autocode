// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_DESTRUCTIBLEMODELDATA_REC_HPP
#define DB_DESTRUCTIBLEMODELDATA_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct DestructibleModelDataRec {
	static constexpr uint32_t columnCount = 19;
	static constexpr uint32_t rowSize = 76;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_State0ImpactEffectDoodadSet;
	int32_t m_State0AmbientDoodadSet;
	int32_t m_State1WMO;
	int32_t m_State1DestructionDoodadSet;
	int32_t m_State1ImpactEffectDoodadSet;
	int32_t m_State1AmbientDoodadSet;
	int32_t m_State2WMO;
	int32_t m_State2DestructionDoodadSet;
	int32_t m_State2ImpactEffectDoodadSet;
	int32_t m_State2AmbientDoodadSet;
	int32_t m_State3WMO;
	int32_t m_State3InitDoodadSet;
	int32_t m_State3AmbientDoodadSet;
	int32_t m_EjectDirection;
	int32_t m_RepairGroundFx;
	int32_t m_DoNotHighlight;
	int32_t m_HealEffect;
	int32_t m_HealEffectSpeed;

	static const char* GetFilename() {
		return "DBFilesClient\\DestructibleModelData.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State0ImpactEffectDoodadSet, sizeof(this->m_State0ImpactEffectDoodadSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State0AmbientDoodadSet, sizeof(this->m_State0AmbientDoodadSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State1WMO, sizeof(this->m_State1WMO), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State1DestructionDoodadSet, sizeof(this->m_State1DestructionDoodadSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State1ImpactEffectDoodadSet, sizeof(this->m_State1ImpactEffectDoodadSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State1AmbientDoodadSet, sizeof(this->m_State1AmbientDoodadSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State2WMO, sizeof(this->m_State2WMO), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State2DestructionDoodadSet, sizeof(this->m_State2DestructionDoodadSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State2ImpactEffectDoodadSet, sizeof(this->m_State2ImpactEffectDoodadSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State2AmbientDoodadSet, sizeof(this->m_State2AmbientDoodadSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State3WMO, sizeof(this->m_State3WMO), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State3InitDoodadSet, sizeof(this->m_State3InitDoodadSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_State3AmbientDoodadSet, sizeof(this->m_State3AmbientDoodadSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_EjectDirection, sizeof(this->m_EjectDirection), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RepairGroundFx, sizeof(this->m_RepairGroundFx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_DoNotHighlight, sizeof(this->m_DoNotHighlight), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_HealEffect, sizeof(this->m_HealEffect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_HealEffectSpeed, sizeof(this->m_HealEffectSpeed), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		return true;
	}
};

#endif