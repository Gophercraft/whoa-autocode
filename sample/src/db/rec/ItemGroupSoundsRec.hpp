// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_ITEMGROUPSOUNDS_REC_HPP
#define DB_ITEMGROUPSOUNDS_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct ItemGroupSoundsRec {
	static constexpr uint32_t columnCount = 5;
	static constexpr uint32_t rowSize = 20;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_Sound[4];

	static const char* GetFilename() {
		return "DBFilesClient\\ItemGroupSounds.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[0], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[1], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[2], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[3], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		return true;
	}
};

#endif