// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_SCREENEFFECT_REC_HPP
#define DB_SCREENEFFECT_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct ScreenEffectRec {
	static constexpr uint32_t columnCount = 10;
	static constexpr uint32_t rowSize = 40;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	const char* m_Name;
	int32_t m_Effect;
	int32_t m_Param[4];
	int32_t m_LightParamsID;
	int32_t m_SoundAmbienceID;
	int32_t m_ZoneMusicID;

	static const char* GetFilename() {
		return "DBFilesClient\\ScreenEffect.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t NameOfs;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &NameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Effect, sizeof(this->m_Effect), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Param[0], sizeof(m_Param[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Param[1], sizeof(m_Param[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Param[2], sizeof(m_Param[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Param[3], sizeof(m_Param[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_LightParamsID, sizeof(this->m_LightParamsID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SoundAmbienceID, sizeof(this->m_SoundAmbienceID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ZoneMusicID, sizeof(this->m_ZoneMusicID), nullptr, nullptr, nullptr)
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