// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_FOOTPRINTTEXTURES_REC_HPP
#define DB_FOOTPRINTTEXTURES_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct FootprintTexturesRec {
	static constexpr uint32_t columnCount = 2;
	static constexpr uint32_t rowSize = 8;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	const char* m_FootstepFilename;

	static const char* GetFilename() {
		return "DBFilesClient\\FootprintTextures.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t FootstepFilenameOfs;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &FootstepFilenameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		if (stringBuffer) {
			this->m_FootstepFilename = &stringBuffer[FootstepFilenameOfs];
		} else {
			this->m_FootstepFilename = "";
		}

		return true;
	}
};

#endif