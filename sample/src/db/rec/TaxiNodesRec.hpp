// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_TAXI_NODES_REC_HPP
#define DB_REC_TAXI_NODES_REC_HPP

#include <cstdint>

class SFile;

class TaxiNodesRec {
    public:
        int32_t m_ID;
        int32_t m_continentID;
        float m_pos[3];
        const char* m_name;
        int32_t m_mountCreatureID[2];

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif