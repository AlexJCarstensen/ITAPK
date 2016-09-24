//
// Created by carty on 9/7/16.
//

#ifndef EXCEPTIONS_DATASET_H
#define EXCEPTIONS_DATASET_H


class DataSet
{
public:
    DataSet(Key *key, Blob *blob) : key_(key), blob_(blob)
    {
        if (!key->isValid())
            throw InvalidKey(key->id());
    }

    void overWrite(const Key *key, const Blob *blob)
    {
        *key_ = *key;
        *blob_ = *blob;

    }

    ~DataSet()
    {
        delete key_;
        delete blob_;
    }

private:
    Key *key_;
    Blob *blob_;
};

void dataSetMethod()
{
    DataSet ds(new Key, new Blob);
    {
        Key k(getKeyValue());
        Blob b(fetchDBBlobByKey(k));
        ds.overWrite(&k, &b);
    }
}

#endif //EXCEPTIONS_DATASET_H
