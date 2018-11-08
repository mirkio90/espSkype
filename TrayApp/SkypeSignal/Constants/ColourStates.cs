
namespace SkypeSignal
{
    public static class ColourStates
    {
        public const string Off = "0";
        public const string Green = "1";
        public const string Red = "2";
        public const string Purple = "3";
        public const string Yellow = "4";
        public const string RedFadeInACall = "5";
        public const string BlueIncomingCall = "6";
        public const string PartyStrobe = "7";

        public static string GetNameFromCode(string Code)
        {
            switch (Code)
            {
                case "0":
                    return "Off";
                case "1":
                    return "Green";
                case "2":
                    return "Red";
                case "3":
                    return "Purple";
                case "4":
                    return "Yellow";
                case "5":
                    return "RedFadeInACall";
                case "6":
                    return "BlueIncomingCall";
                default:
                    break;
            }
            return null;
        }
    }
}