library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity out_logic_intf is
	Port( IN_BUS : in std_logic_vector(2 downto 0);
			TEST : in std_logic;
			OUT_BUS : out std_logic_vector(7 downto 0)
			);
end out_logic_intf;

architecture out_logic_arch of out_logic_intf is

begin

OUT_BUS(0) <= ((not IN_BUS(2) and not IN_BUS(1) and not IN_BUS(0))
					or(IN_BUS(2) and IN_BUS(1) and not IN_BUS(0))
					or not TEST);
											
OUT_BUS(1) <= ((not IN_BUS(2) and not IN_BUS(1) and IN_BUS(0))
					or (IN_BUS(2) and not IN_BUS(1) and IN_BUS(0))
					or (IN_BUS(2) and IN_BUS(1) and not IN_BUS(0))
					or not TEST);
					
OUT_BUS(2) <= ((not IN_BUS(2) and IN_BUS(1) and not IN_BUS(0))
					or (IN_BUS(2) and not IN_BUS(1) and not IN_BUS(0))
					or (IN_BUS(2) and not IN_BUS(1) and IN_BUS(0))
					or (IN_BUS(2) and  IN_BUS(1) and not IN_BUS(0))
					or not TEST);

OUT_BUS(3) <= ((not IN_BUS(2) and IN_BUS(1) and IN_BUS(0))
					or (IN_BUS(2) and not IN_BUS(1) and not IN_BUS(0))
					or (IN_BUS(2) and not IN_BUS(1) and IN_BUS(0))
					or (IN_BUS(2) and  IN_BUS(1) and not IN_BUS(0))
					or not TEST);
					
OUT_BUS(4) <= ((not IN_BUS(2) and IN_BUS(1) and IN_BUS(0) and TEST)
					or (IN_BUS(2) and not IN_BUS(1) and not IN_BUS(0)and TEST)
					or (IN_BUS(2) and not IN_BUS(1) and IN_BUS(0)and TEST)
					or (IN_BUS(2) and  IN_BUS(1) and not IN_BUS(0)and TEST));
					
OUT_BUS(5) <= ((not IN_BUS(2) and IN_BUS(1) and not IN_BUS(0)and TEST)
					or (IN_BUS(2) and not IN_BUS(1) and not IN_BUS(0)and TEST)
					or (IN_BUS(2) and not IN_BUS(1) and IN_BUS(0)and TEST)
					or (IN_BUS(2) and  IN_BUS(1) and not IN_BUS(0)and TEST));
					
OUT_BUS(6) <= ((not IN_BUS(2) and not IN_BUS(1) and IN_BUS(0)and TEST)
					or (IN_BUS(2) and not IN_BUS(1) and IN_BUS(0)and TEST)
					or (IN_BUS(2) and IN_BUS(1) and not IN_BUS(0)and TEST));
					
OUT_BUS(7) <= ((not IN_BUS(2) and not IN_BUS(1) and not IN_BUS(0)and TEST)
					or(IN_BUS(2) and IN_BUS(1) and not IN_BUS(0)and TEST));











end out_logic_arch;