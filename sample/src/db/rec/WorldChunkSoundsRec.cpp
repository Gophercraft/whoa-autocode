// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/WorldChunkSoundsRec.hpp"

const char* WorldChunkSoundsRec::GetFilename() {
    return "DBFilesClient\\WorldChunkSounds.dbc";
}

bool WorldChunkSoundsRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ChunkX, sizeof(this->m_ChunkX), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ChunkY, sizeof(this->m_ChunkY), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SubchunkX, sizeof(this->m_SubchunkX), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SubchunkY, sizeof(this->m_SubchunkY), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ZoneIntroMusicID, sizeof(this->m_ZoneIntroMusicID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ZoneMusicID, sizeof(this->m_ZoneMusicID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SoundAmbienceID, sizeof(this->m_SoundAmbienceID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SoundProviderPreferencesID, sizeof(this->m_SoundProviderPreferencesID), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}