// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_WORLDSTATEZONESOUNDS_REC_HPP
#define DB_WORLDSTATEZONESOUNDS_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct WorldStateZoneSoundsRec {
	static constexpr uint32_t columnCount = 8;
	static constexpr uint32_t rowSize = 32;
	static constexpr bool indexIsID = true;

	int32_t m_WorldStateID;
	int32_t m_WorldStateValue;
	int32_t m_AreaID;
	int32_t m_WMOAreaID;
	int32_t m_ZoneIntroMusicID;
	int32_t m_ZoneMusicID;
	int32_t m_SoundAmbienceID;
	int32_t m_SoundProviderPreferencesID;

	static const char* GetFilename() {
		return "DBFilesClient\\WorldStateZoneSounds.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		if (
			!SFile::Read(f, &this->m_WorldStateID, sizeof(this->m_WorldStateID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_WorldStateValue, sizeof(this->m_WorldStateValue), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AreaID, sizeof(this->m_AreaID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_WMOAreaID, sizeof(this->m_WMOAreaID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ZoneIntroMusicID, sizeof(this->m_ZoneIntroMusicID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ZoneMusicID, sizeof(this->m_ZoneMusicID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SoundAmbienceID, sizeof(this->m_SoundAmbienceID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SoundProviderPreferencesID, sizeof(this->m_SoundProviderPreferencesID), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		return true;
	}
};

#endif