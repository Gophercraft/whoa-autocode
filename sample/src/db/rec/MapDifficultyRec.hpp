// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_MAPDIFFICULTY_REC_HPP
#define DB_MAPDIFFICULTY_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct MapDifficultyRec {
	static constexpr uint32_t columnCount = 23;
	static constexpr uint32_t rowSize = 92;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_MapID;
	int32_t m_Difficulty;
	const char* m_Message_lang;
	int32_t m_RaidDuration;
	int32_t m_MaxPlayers;
	const char* m_Difficultystring;

	static const char* GetFilename() {
		return "DBFilesClient\\MapDifficulty.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t Message_langOfs[16];
		uint32_t Message_langMask;
		uint32_t DifficultystringOfs;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_MapID, sizeof(this->m_MapID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Difficulty, sizeof(this->m_Difficulty), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &Message_langMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_RaidDuration, sizeof(this->m_RaidDuration), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_MaxPlayers, sizeof(this->m_MaxPlayers), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &DifficultystringOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		if (stringBuffer) {
			this->m_Message_lang = &stringBuffer[Message_langOfs[CURRENT_LANGUAGE]];
			this->m_Difficultystring = &stringBuffer[DifficultystringOfs];
		} else {
			this->m_Message_lang = "";
			this->m_Difficultystring = "";
		}

		return true;
	}
};

#endif