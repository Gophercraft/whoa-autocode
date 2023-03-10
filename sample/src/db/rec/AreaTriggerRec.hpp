// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_AREA_TRIGGER_REC_HPP
#define DB_REC_AREA_TRIGGER_REC_HPP

#include <cstdint>

class SFile;

class AreaTriggerRec {
    public:
        int32_t m_ID;
        int32_t m_continentID;
        float m_pos[3];
        float m_radius;
        float m_boxLength;
        float m_boxWidth;
        float m_boxHeight;
        float m_boxYaw;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif