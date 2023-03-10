// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_NAME_GEN_REC_HPP
#define DB_REC_NAME_GEN_REC_HPP

#include <cstdint>

class SFile;

class NameGenRec {
    public:
        int32_t m_ID;
        const char* m_name;
        int32_t m_raceID;
        int32_t m_sex;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif