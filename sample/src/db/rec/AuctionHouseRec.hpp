// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_AUCTION_HOUSE_REC_HPP
#define DB_REC_AUCTION_HOUSE_REC_HPP

#include <cstdint>

class SFile;

class AuctionHouseRec {
    public:
        int32_t m_ID;
        int32_t m_factionID;
        int32_t m_depositRate;
        int32_t m_consignmentRate;
        const char* m_name;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif