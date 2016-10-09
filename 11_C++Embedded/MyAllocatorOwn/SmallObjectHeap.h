//
// Created by ubuntuudvikling on 10/3/16.
//

#ifndef MYALLOCATOROWN_SMALLOBJECTHEAP_H
#define MYALLOCATOROWN_SMALLOBJECTHEAP_H


#include <vector>

namespace details {

    class Page {
    public:
        // allocate memory and initialize page
        void initialize(std::size_t blockSize, unsigned char blocks);

        // release memory
        void release();

        // return number of free block in page
        unsigned char blocksFree() const { return blocksAvailable_; }

        // return number og blocks in page
        unsigned char maxBlocks() const { return maxBlocks_; }

        // is p allocated from this page
        bool isBlockInPage(void *p) const { return p >= data_ && p < data_ + maxBlocks_ * blockSize_; }

        // allocate block from page. Return NULL if no block is avaible
        void *allocate();

        // free block. Only pointers previously allocated with allocate are leagel
        void deallocate(void *p);

    private:
        unsigned char *data_;
        std::size_t blockSize_;
        unsigned char firstAvailableBlock_;
        unsigned char blocksAvailable_;
        unsigned char maxBlocks_;
    };

    inline void Page::initialize(std::size_t blockSize, unsigned char blocks) {
        data_ = new unsigned char[blockSize * blocks];

        blockSize_ = blockSize;
        firstAvailableBlock_ = 0;
        blocksAvailable_ = blocks;
        maxBlocks_ = blocks;

        unsigned char i = 0;
        for (unsigned char *p = data_; i != blocks; p += blockSize) {
            *p = ++i;
        }
    }

    inline void Page::release() {
        delete[] data_;
    }

    inline void *Page::allocate() {
        if (!blocksAvailable_) return 0;

        unsigned char *result = data_ + (firstAvailableBlock_ * blockSize_);
        firstAvailableBlock_ = *result;
        --blocksAvailable_;

        return result;
    }

    inline void Page::deallocate(void *p) {
        unsigned char *toRelease = static_cast<unsigned char *>( p );

        *toRelease = firstAvailableBlock_;
        firstAvailableBlock_ = static_cast<unsigned char>((toRelease - data_) / blockSize_ );

        ++blocksAvailable_;
    }


} // namespace details

template<std::size_t S>
class SmallObjectHeap {
public:


    static SmallObjectHeap &Instance() {
        static SmallObjectHeap soh;
        return soh;
    }

    void allocate() {
        for (auto iterator = pages_.begin(); iterator != pages_.end(); ++iterator) {
            if (iterator->blocksFree() > 0) {
                iterator->allocate();
                break;
            }
            if (iterator == pages_.end()) {
                details::Page page;
                page.initialize(size_, blocks_);
                page.allocate();
                pages_.push_back(page);
            }
        }

    }

    void deallocate() {

    }

private:
    SmallObjectHeap() : size_(S) {};

    virtual ~SmallObjectHeap() {
        for (auto &&page : pages_) {
            page.release();
        }
    };


private:
    std::vector<details::Page> pages_;
    std::size_t size_;
    std::size_t blocks_{15};
};

#endif //MYALLOCATOROWN_SMALLOBJECTHEAP_H
