// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_RESEARCH_BRANCH_REC_HPP
#define DB_REC_RESEARCH_BRANCH_REC_HPP

#include <cstdint>

class SFile;

class ResearchBranchRec {
    public:
        int32_t m_ID;
        const char* m_name;
        int32_t m_researchFieldID;
        int32_t m_currencyID;
        const char* m_texture;
        int32_t m_itemID;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif