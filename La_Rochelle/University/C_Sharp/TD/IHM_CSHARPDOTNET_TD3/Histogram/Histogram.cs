using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Histogram
{
    [Serializable]
    class Histogram
    {
        public int m_size;
        public List<Intervalle> m_list;
   
        public Histogram(int histo_size)
        {
            m_size = histo_size;
            m_list = new List<Intervalle>(histo_size);
        }

    }
     
}
