#include <string>
#include <system_error>
#include <stdexcept>

using namespace std;
// No comments
class TimeServer {
public:
    string GetCurrentTime() {
        try {
            string temp = AskTimeServer();
            last_fetched_time = temp;
            return last_fetched_time;
        }
        catch (system_error&) {
            return last_fetched_time;
        }
        catch (exception&) {
            throw;
        }
    }
private:
    string last_fetched_time = "00:00:00";
};
