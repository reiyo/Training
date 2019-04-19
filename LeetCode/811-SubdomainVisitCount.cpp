class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mymap;
        
        for (auto it=cpdomains.begin(); it!=cpdomains.end(); ++it) {
            const string& cpdomain = *it;

            size_t found = cpdomain.find(" ");
            int cnt = stoi(cpdomain.substr(0, found));
            string domain = cpdomain.substr(found+1);
            size_t pos = 0;
            //if (!mymap.count(domain)) mymap[domain] = 0;
            mymap[domain] += cnt;
            
            while ((found = domain.find('.', pos))!=string::npos) {
                const string subdomain = domain.substr(found+1);
                //if (!mymap.count(subdomain)) mymap[subdomain] = 0;
                mymap[subdomain] += cnt;
                pos = found+1;
            }
        }
        
        vector<string> output;
        
        for (auto it=mymap.begin(); it!=mymap.end(); ++it) {
            output.push_back(to_string(it->second) + " " + it->first);
        }
        
        return output;
    }
};
