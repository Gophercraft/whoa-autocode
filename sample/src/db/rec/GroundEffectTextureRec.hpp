// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_GROUND_EFFECT_TEXTURE_REC_HPP
#define DB_REC_GROUND_EFFECT_TEXTURE_REC_HPP

#include <cstdint>

class SFile;

class GroundEffectTextureRec {
    public:
        int32_t m_ID;
        int32_t m_doodadID[4];
        int32_t m_doodadWeight[4];
        int32_t m_density;
        int32_t m_sound;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif