// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_GTOCTREGENHP_REC_HPP
#define DB_GTOCTREGENHP_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct gtOCTRegenHPRec {
	static constexpr uint32_t columnCount = 1;
	static constexpr uint32_t rowSize = 4;
	static constexpr bool indexIsID = true;

	float m_Data;

	static const char* GetFilename() {
		return "DBFilesClient\\gtOCTRegenHP.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		if (
			!SFile::Read(f, &this->m_Data, sizeof(this->m_Data), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		return true;
	}
};

#endif