// Copyright(C) 2014 kittikun
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// This work is compatible with the Dominion Rules role-playing system.To learn more about
// Dominion Rules, visit the Dominion Rules web site at <http://www.dominionrules.org>

#include "skill_impl.h"

#include <memory>
#include <boost/lexical_cast.hpp>

#include "classid.h"
#include "database_impl.h"

namespace Dominion
{
    SkillImpl::SkillImpl(const uint_fast32_t id) :
        Data(id),
        level_(1),
        target_(-1)
    {}

    int SkillImpl::LoadFromDB(void* data, int argc, char** argv, char** col)
    {
        DatabaseImpl* db = static_cast<DatabaseImpl*>(data);
        std::shared_ptr<SkillImpl> skill;

        for (int i = 0; i < argc; ++i) {
            if (argv[i] == nullptr)
                continue;

            if (strcmp(col[i], "Id") == 0) {
                uint_fast32_t id = ClassID_Skill + boost::lexical_cast<uint_fast32_t>(argv[i]);
                skill = std::make_shared<SkillImpl>(id);
            } else if (strcmp(col[i], "type") == 0) {
                skill->type_ = static_cast<ESkillType>(boost::lexical_cast<int32_t>(argv[i]));
            } else if (strcmp(col[i], "name") == 0) {
                skill->name_ = argv[i];
            } else if (strcmp(col[i], "dependency") == 0) {
                skill->dependency_ = static_cast<ESkillDependency>(boost::lexical_cast<int32_t>(argv[i]));
            } else if (strcmp(col[i], "target") == 0) {
                skill->target_ = boost::lexical_cast<uint_fast32_t>(argv[i]);
            } else if (strcmp(col[i], "bySentient") == 0) {
                skill->usableRace_[ERace::RaceHuman] = boost::lexical_cast<bool>(argv[i]);;
                skill->usableRace_[ERace::RaceElf] = boost::lexical_cast<bool>(argv[i]);;
                skill->usableRace_[ERace::RaceDwarf] = boost::lexical_cast<bool>(argv[i]);;
                skill->usableRace_[ERace::RaceHalfling] = boost::lexical_cast<bool>(argv[i]);;
            } else if (strcmp(col[i], "byHumanoid") == 0) {
                skill->usableRace_[ERace::RaceHumanoid] = boost::lexical_cast<bool>(argv[i]);;
            } else if (strcmp(col[i], "byBeast") == 0) {
                skill->usableRace_[ERace::RaceBeast] = boost::lexical_cast<bool>(argv[i]);;
            }
        }

        db->AddData<Skill>(skill);

        return 0;
    }

    uint_fast32_t SkillImpl::CostToRaise(uint_fast8_t toLevel)
    {
        // Triangular numbers: a(n) = C(n+1,2) = n(n+1)/2 = 0+1+2+...+n.
        // https://oeis.org/A000217
        static std::array<uint_fast32_t, 54> costPerLevel = {
            0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105,
            120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351,
            378, 406, 435, 465, 496, 528, 561, 595, 630, 666, 703, 741,
            780, 820, 861, 903, 946, 990, 1035, 1081, 1128, 1176, 1225,
            1275, 1326, 1378, 1431};

        if (toLevel >= costPerLevel.size())
            throw std::out_of_range("Requested level is too high");

        uint_fast32_t current = costPerLevel[level_];
        uint_fast32_t wanted = costPerLevel[level_];

        return wanted - current;
    }
} // namespace Dominion
