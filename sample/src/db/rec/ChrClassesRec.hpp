// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_CHRCLASSES_REC_HPP
#define DB_CHRCLASSES_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct ChrClassesRec {
	static constexpr uint32_t columnCount = 60;
	static constexpr uint32_t rowSize = 240;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_DamageBonusStat;
	int32_t m_DisplayPower;
	const char* m_PetNameToken;
	const char* m_Name_lang;
	const char* m_Name_female_lang;
	const char* m_Name_male_lang;
	const char* m_Filename;
	int32_t m_SpellClassSet;
	int32_t m_Flags;
	int32_t m_CinematicSequenceID;
	int32_t m_Required_expansion;

	static const char* GetFilename() {
		return "DBFilesClient\\ChrClasses.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t PetNameTokenOfs;
		uint32_t Name_langOfs[16];
		uint32_t Name_langMask;
		uint32_t Name_female_langOfs[16];
		uint32_t Name_female_langMask;
		uint32_t Name_male_langOfs[16];
		uint32_t Name_male_langMask;
		uint32_t FilenameOfs;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_DamageBonusStat, sizeof(this->m_DamageBonusStat), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_DisplayPower, sizeof(this->m_DisplayPower), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &PetNameTokenOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
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
			|| !SFile::Read(f, &Name_female_langOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_female_langMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Name_male_langMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &FilenameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SpellClassSet, sizeof(this->m_SpellClassSet), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Flags, sizeof(this->m_Flags), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_CinematicSequenceID, sizeof(this->m_CinematicSequenceID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Required_expansion, sizeof(this->m_Required_expansion), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		if (stringBuffer) {
			this->m_PetNameToken = &stringBuffer[PetNameTokenOfs];
			this->m_Name_lang = &stringBuffer[Name_langOfs[CURRENT_LANGUAGE]];
			this->m_Name_female_lang = &stringBuffer[Name_female_langOfs[CURRENT_LANGUAGE]];
			this->m_Name_male_lang = &stringBuffer[Name_male_langOfs[CURRENT_LANGUAGE]];
			this->m_Filename = &stringBuffer[FilenameOfs];
		} else {
			this->m_PetNameToken = "";
			this->m_Name_lang = "";
			this->m_Name_female_lang = "";
			this->m_Name_male_lang = "";
			this->m_Filename = "";
		}

		return true;
	}
};

#endif