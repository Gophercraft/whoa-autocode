// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_QUESTSORT_REC_HPP
#define DB_QUESTSORT_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct QuestSortRec {
	static constexpr uint32_t columnCount = 18;
	static constexpr uint32_t rowSize = 72;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	const char* m_SortName_lang;

	static const char* GetFilename() {
		return "DBFilesClient\\QuestSort.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t SortName_langOfs[16];
		uint32_t SortName_langMask;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &SortName_langMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		if (stringBuffer) {
			this->m_SortName_lang = &stringBuffer[SortName_langOfs[CURRENT_LANGUAGE]];
		} else {
			this->m_SortName_lang = "";
		}

		return true;
	}
};

#endif