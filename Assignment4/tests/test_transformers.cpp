// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include <gtest/gtest.h>
#include "../src/transformer.h"
#include "../src/autobot.h"
#include "../src/decepticon.h"
#include "../src/minicon.h"
#include "../src/weapon.h"
#include "../src/pilot.h"
#include <vector>
#include <sstream>

TEST(TransformerTest, Initialization)
{
    Weapon w(50, 10);
    // Transformer t; // Abstract class, cannot instantiate
    Autobot a(1, 100, 50, w, 90, true);
    EXPECT_EQ(a.getLevel(), 1);
    EXPECT_EQ(a.getStrength(), 100);
}

TEST(VirtualMethodTest, OpenFireOverride)
{
    Weapon w(50, 10);
    Autobot a(1, 100, 50, w, 90, true);
    Transformer* t = &a;
    
    // Testing captured output would be ideal, but verifying invocation doesn't crash is basic step.
    // In a real scenario we might redirect stdout.
    t->openFire(); 
}

TEST(VirtualMethodTest, PureVirtualTransform)
{
    Weapon w(50, 10);
    Decepticon d;
    Transformer* t = &d;
    t->transform(); // Should call Decepticon::transform
}

TEST(OperatorTest, Output)
{
    Weapon w(50, 10);
    Autobot a(1, 100, 50, w, 90, true);
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "Autobot(Level: 1, Empathy: 90)");
}

TEST(HierarchyTest, VectorOfPointers)
{
    Weapon w(10, 10);
    std::vector<Transformer*> bots;
    
    // Create 9 objects (3 of each)
    for (int i = 0; i < 3; ++i) {
        bots.push_back(new Autobot(i, 100, 50, w, 50, true));
        bots.push_back(new Decepticon(i, 200, 50, w, 100, false));
        bots.push_back(new MiniCon(i, 20, 10, w, 1, false));
    }
    
    EXPECT_EQ(bots.size(), 9);
    
    // Iterate and call virtual methods
    for (Transformer* bot : bots) {
        bot->transform();
        bot->openFire();
        bot->ultraMove();
    }
    
    // Clean up
    for (Transformer* bot : bots) {
        delete bot;
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
