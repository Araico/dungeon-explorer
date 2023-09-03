namespace SpellEnums {

enum class School {
   ABJURATION,
   CONJURATION,
   DIVINATION,
   DUNAMANCY,
   ENCHANTMENT,
   EVOCATION,
   ILLUSION,
   NECROMANCY,
   TRANSMUTATION
};

enum class RangeType {
   DISTANCE,
   TOUCH,
   SELF,
};

enum class CastType {
   REACTION,
   ACTION,
   B_ACTION,
   MINUTE,
   HOUR,
};

enum class DurationType {
   UNTIL_D,   // Until dispelled
   HOUR,      // x hour
   ROUND,     // x round
   INSTANT,   // Instantaneous
   CON_MIN,   // Concentration, up to X minutes
   CON_HOUR,  // Concentration, up to x hour
   CON_DAY,   // Concentration, up to x day
};

};  // namespace SpellEnums