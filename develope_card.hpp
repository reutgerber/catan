#pragma once
#include <vector>
#include <random>

using namespace std;
namespace ariel {
   
    class Player;
    class Board;

    class DevelopCard {
    protected:
        std::string type;
    
      
    public:
        DevelopCard(const std::string& type) : type(type) {}
        virtual ~DevelopCard() = default;
        virtual void use(Player& player, std::vector<Player*>& players, Board& board) = 0;
        std::string getType() const { return type; }
    };
    
    //type1: promotion
    class PromotionCard : public DevelopCard {
    public:
        PromotionCard(const std::string& type) : DevelopCard(type) {}
        ~PromotionCard() override = default;
    };

    //type2: knights
    class KnightCard : public DevelopCard {
    public:
        KnightCard() : DevelopCard("Knight") {}
        void use(Player& player, std::vector<Player*>& players, Board& board) override;
    };

    //type3: points
    class VictoryPointCard : public DevelopCard {
    public:
        VictoryPointCard() : DevelopCard("VictoryPoint") {}
        void use(Player& player, std::vector<Player*>& players, Board& board) override;
    };

    class MonopolyCard : public PromotionCard {
    public:
        MonopolyCard() : PromotionCard("Monopoly") {}
        void use(Player& player, std::vector<Player*>& players, Board& board) override;
    };

    class RoadBuildingCard : public PromotionCard {
    public:
        RoadBuildingCard() : PromotionCard("RoadBuilding") {}
        void use(Player& player, std::vector<Player*>& players, Board& board) override;
    };

    class YearOfPlentyCard : public PromotionCard {
    public:
        YearOfPlentyCard() : PromotionCard("YearOfPlenty") {}
        void use(Player& player, std::vector<Player*>& players, Board& board) override;
    };

    
    class Deck {
            std::vector<DevelopCard*> deck;
            const int knightCardCount = 3;

        public:
            Deck();
            ~Deck();

            

            DevelopCard* drawCard();
            
        };





}

