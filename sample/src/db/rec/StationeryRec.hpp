// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_STATIONERY_REC_HPP
#define DB_REC_STATIONERY_REC_HPP

#include <cstdint>

class SFile;

class StationeryRec {
    public:
        int32_t m_ID;
        int32_t m_itemID;
        const char* m_texture;
        int32_t m_flags;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif