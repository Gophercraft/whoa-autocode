// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_ITEMRANDOMSUFFIX_REC_HPP
#define DB_ITEMRANDOMSUFFIX_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct ItemRandomSuffixRec {
	static constexpr uint32_t columnCount = 29;
	static constexpr uint32_t rowSize = 116;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	const char* m_Name_lang;
	const char* m_InternalName;
	int32_t m_Enchantment[5];
	int32_t m_AllocationPct[5];

	static const char* GetFilename() {
		return "DBFilesClient\\ItemRandomSuffix.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t Name_langOfs[16];
		uint32_t Name_langMask;
		uint32_t InternalNameOfs;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_langMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &InternalNameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Enchantment[0], sizeof(m_Enchantment[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Enchantment[1], sizeof(m_Enchantment[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Enchantment[2], sizeof(m_Enchantment[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Enchantment[3], sizeof(m_Enchantment[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Enchantment[4], sizeof(m_Enchantment[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AllocationPct[0], sizeof(m_AllocationPct[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AllocationPct[1], sizeof(m_AllocationPct[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AllocationPct[2], sizeof(m_AllocationPct[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AllocationPct[3], sizeof(m_AllocationPct[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AllocationPct[4], sizeof(m_AllocationPct[0]), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		if (stringBuffer) {
			this->m_Name_lang = &stringBuffer[Name_langOfs[CURRENT_LANGUAGE]];
			this->m_InternalName = &stringBuffer[InternalNameOfs];
		} else {
			this->m_Name_lang = "";
			this->m_InternalName = "";
		}

		return true;
	}
};

#endif