// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_PETITIONTYPE_REC_HPP
#define DB_PETITIONTYPE_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct PetitionTypeRec {
	static constexpr uint32_t columnCount = 3;
	static constexpr uint32_t rowSize = 12;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	const char* m_Name;
	int32_t m_Type;

	static const char* GetFilename() {
		return "DBFilesClient\\PetitionType.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t NameOfs;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Type, sizeof(this->m_Type), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		if (stringBuffer) {
			this->m_Name = &stringBuffer[NameOfs];
		} else {
			this->m_Name = "";
		}

		return true;
	}
};

#endif