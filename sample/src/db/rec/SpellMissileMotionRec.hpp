// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_SPELL_MISSILE_MOTION_REC_HPP
#define DB_REC_SPELL_MISSILE_MOTION_REC_HPP

#include <cstdint>

class SFile;

class SpellMissileMotionRec {
    public:
        int32_t m_ID;
        const char* m_name;
        const char* m_scriptBody;
        int32_t m_flags;
        int32_t m_missileCount;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif