// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_WORLD_STATE_ZONE_SOUNDS_REC_HPP
#define DB_REC_WORLD_STATE_ZONE_SOUNDS_REC_HPP

#include <cstdint>

class SFile;

class WorldStateZoneSoundsRec {
    public:
        int32_t m_worldStateID;
        int32_t m_worldStateValue;
        int32_t m_areaID;
        int32_t m_wmoareaID;
        int32_t m_zoneIntroMusicID;
        int32_t m_zoneMusicID;
        int32_t m_soundAmbienceID;
        int32_t m_soundProviderPreferencesID;
        int32_t m_generatedID;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif