// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_SPELLAURAOPTIONS_REC_HPP
#define DB_SPELLAURAOPTIONS_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct SpellAuraOptionsRec {
	static constexpr uint32_t columnCount = 5;
	static constexpr uint32_t rowSize = 20;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_CumulativeAura;
	int32_t m_ProcChance;
	int32_t m_ProcCharges;
	int32_t m_ProcTypeMask;

	static const char* GetFilename() {
		return "DBFilesClient\\SpellAuraOptions.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CumulativeAura, sizeof(this->m_CumulativeAura), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ProcChance, sizeof(this->m_ProcChance), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ProcCharges, sizeof(this->m_ProcCharges), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ProcTypeMask, sizeof(this->m_ProcTypeMask), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		return true;
	}
};

#endif