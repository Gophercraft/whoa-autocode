// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_ARMORLOCATION_REC_HPP
#define DB_ARMORLOCATION_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct ArmorLocationRec {
	static constexpr uint32_t columnCount = 6;
	static constexpr uint32_t rowSize = 24;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	float m_Clothmodifier;
	float m_Leathermodifier;
	float m_Chainmodifier;
	float m_Platemodifier;
	float m_Modifier;

	static const char* GetFilename() {
		return "DBFilesClient\\ArmorLocation.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Clothmodifier, sizeof(this->m_Clothmodifier), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Leathermodifier, sizeof(this->m_Leathermodifier), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Chainmodifier, sizeof(this->m_Chainmodifier), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Platemodifier, sizeof(this->m_Platemodifier), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Modifier, sizeof(this->m_Modifier), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		return true;
	}
};

#endif