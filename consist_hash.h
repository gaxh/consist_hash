#ifndef __CONSIST_HASH_H__
#define __CONSIST_HASH_H__

#include <map>

template<typename NodeType, typename HashType>
class consist_hash
{
private:
    using hash_result_type = typename HashType::result_type;
    std::map<hash_result_type, NodeType> m_nodemap;
    HashType m_hasher;

public:
    bool insert_node(const NodeType &node)
    {
        hash_result_type hash_code = m_hasher(node);

        if( m_nodemap.find(hash_code) != m_nodemap.end() )
        {
            return false;
        }

        m_nodemap[hash_code] = node;
        return true;
    }

    bool delete_node(const NodeType &node)
    {
        hash_result_type hash_code = m_hasher(node);

        auto iter = m_nodemap.find(hash_code);

        if(iter == m_nodemap.end())
        {
            return false;
        }

        NodeType &exist = iter->second;

        if( exist != node )
        {
            return false;
        }

        m_nodemap.erase(iter);
        return true;
    }

    size_t size()
    {
        return m_nodemap.size();
    }

    bool find_node(hash_result_type hash_code, NodeType &node) const
    {
        if(m_nodemap.size() <= 0)
        {
            return false;
        }

        auto iter = m_nodemap.lower_bound(hash_code);

        if(iter == m_nodemap.end())
        {
            node = m_nodemap.begin()->second;
            return true;
        }
        else
        {
            node = iter->second;
            return true;
        }
    }
};


#endif

