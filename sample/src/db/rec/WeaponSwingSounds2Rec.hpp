// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_WEAPON_SWING_SOUNDS2_REC_HPP
#define DB_REC_WEAPON_SWING_SOUNDS2_REC_HPP

#include <cstdint>

class SFile;

class WeaponSwingSounds2Rec {
    public:
        int32_t m_ID;
        int32_t m_swingType;
        int32_t m_crit;
        int32_t m_soundID;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif