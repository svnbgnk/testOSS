#include <seqan3/alignment/scoring/nucleotide_scoring_scheme.hpp>
#include <seqan3/alignment/pairwise/align_pairwise.hpp>
#include <seqan3/alignment/scoring/aminoacid_scoring_scheme.hpp>
#include <seqan3/alphabet/nucleotide/dna4.hpp>
#include <seqan3/alphabet/aminoacid/all.hpp>
// #include <seqan3/alignment/all.hpp>
#include <seqan3/io/alignment_file/all.hpp>
#include <seqan3/alphabet/quality/phred42.hpp>
/*
#include <seqan3/search/all.hpp>
#include <seqan3/search/fm_index/bi_fm_index.hpp>   // for using the bi_fm_index
#include <seqan3/search/fm_index/fm_index.hpp>      // for using the fm_index
#include <seqan3/search/algorithm/search.hpp>*/

#include <../../seqan3/test/unit/search/helper_search_scheme.hpp>

using namespace seqan3;


template <class>
struct nothing;

template <typename T>
void print_vector(std::vector<T> v)
{
    for(int i = 0; i < v.size(); ++i){
        std::cout << static_cast<int>(v[i]) << ", ";
    }
    std::cout << "\n";
}

int main(int argc, char * argv[])
{

     // This is trick to let the compiler tell you what type ss (as an error message) has. 
//     auto ss = trivial_search_scheme(0, 3 , 5);
//     nothing<decltype(ss)> a;


    std::vector<detail::search_dyn> triv_ss = trivial_search_scheme(0, 3 , 5);

    for(int i = 0; i < triv_ss.size(); ++i){
        auto s = triv_ss[i];
        for(int j = 0; j < s.blocks(); ++j)
        {
            std::cout << (int)s.pi[j] << "\t";
        }
        std::cout << "\n";
        for(int j = 0; j < s.blocks(); ++j)
        {
            std::cout << (int)s.l[j] << "\t";
        }
        std::cout << "\n";
        for(int j = 0; j < s.blocks(); ++j)
        {
            std::cout << (int)s.u[j] << "\t";
        }
        std::cout << "\n";

    }

    std::cout << "Print All Error Distributions\n";
    std::vector<std::vector<uint8_t> > all_dis;
    search_scheme_error_distribution(all_dis, triv_ss);

    for(int i = 0; i < all_dis.size(); ++i)
    {
        print_vector(all_dis[i]);
    }



//

    std::cout << "fin\n";


    return 0;
}
