// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_CINEMATICSEQUENCES_REC_HPP
#define DB_CINEMATICSEQUENCES_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct CinematicSequencesRec {
	static constexpr uint32_t columnCount = 10;
	static constexpr uint32_t rowSize = 40;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_SoundID;
	int32_t m_Camera[8];

	static const char* GetFilename() {
		return "DBFilesClient\\CinematicSequences.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SoundID, sizeof(this->m_SoundID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Camera[0], sizeof(m_Camera[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Camera[1], sizeof(m_Camera[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Camera[2], sizeof(m_Camera[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Camera[3], sizeof(m_Camera[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Camera[4], sizeof(m_Camera[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Camera[5], sizeof(m_Camera[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Camera[6], sizeof(m_Camera[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Camera[7], sizeof(m_Camera[0]), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		return true;
	}
};

#endif