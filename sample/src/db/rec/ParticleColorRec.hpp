// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_PARTICLECOLOR_REC_HPP
#define DB_PARTICLECOLOR_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct ParticleColorRec {
	static constexpr uint32_t columnCount = 10;
	static constexpr uint32_t rowSize = 40;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_Start[3];
	int32_t m_MID[3];
	int32_t m_End[3];

	static const char* GetFilename() {
		return "DBFilesClient\\ParticleColor.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Start[0], sizeof(m_Start[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Start[1], sizeof(m_Start[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Start[2], sizeof(m_Start[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_MID[0], sizeof(m_MID[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_MID[1], sizeof(m_MID[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_MID[2], sizeof(m_MID[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_End[0], sizeof(m_End[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_End[1], sizeof(m_End[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_End[2], sizeof(m_End[0]), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		return true;
	}
};

#endif