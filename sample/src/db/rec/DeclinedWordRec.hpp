// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_DECLINEDWORD_REC_HPP
#define DB_DECLINEDWORD_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct DeclinedWordRec {
	static constexpr uint32_t columnCount = 2;
	static constexpr uint32_t rowSize = 8;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	const char* m_Word;

	static const char* GetFilename() {
		return "DBFilesClient\\DeclinedWord.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t WordOfs;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &WordOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		if (stringBuffer) {
			this->m_Word = &stringBuffer[WordOfs];
		} else {
			this->m_Word = "";
		}

		return true;
	}
};

#endif