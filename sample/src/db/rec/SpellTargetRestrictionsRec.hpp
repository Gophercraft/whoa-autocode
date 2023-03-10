// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_SPELL_TARGET_RESTRICTIONS_REC_HPP
#define DB_REC_SPELL_TARGET_RESTRICTIONS_REC_HPP

#include <cstdint>

class SFile;

class SpellTargetRestrictionsRec {
    public:
        int32_t m_ID;
        int32_t m_maxTargets;
        int32_t m_maxTargetLevel;
        int32_t m_targetCreatureType;
        int32_t m_targets;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif