----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:13:46 04/27/2023 
-- Design Name: 
-- Module Name:    ALU - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ALU_intf is
port(
		IN_SEL_OUT_BUS : IN STD_LOGIC_VECTOR(7 downto 0);
		ACC_DATA_OUT_BUS : IN STD_LOGIC_VECTOR(7 downto 0);
		OP_CODE_BUS : IN STD_LOGIC_VECTOR(1 downto 0);
		RESET : IN STD_LOGIC;
		ACC_DATA_IN_BUS : OUT STD_LOGIC_VECTOR(7 downto 0);
		OVERFLOW : OUT STD_LOGIC := '0'
		);
end ALU_intf;

architecture ALU_arch of ALU_intf is

begin
ALU : process(OP_CODE_BUS, IN_SEL_OUT_BUS, ACC_DATA_OUT_BUS)
		variable A : unsigned(7 downto 0);
		variable B : unsigned(7 downto 0); 
	 begin
		A := unsigned(ACC_DATA_OUT_BUS);
		B := unsigned(IN_SEL_OUT_BUS);
		
		if(RESET = '1')then
			OVERFLOW <= '0';
		end if;
		
		case(OP_CODE_BUS) is
			when "00" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(B);
			when "01" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(A + B);
			if ((A+B) > "11111111") then
                OVERFLOW <= '1';
            end if;
			when "10" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(RESIZE(unsigned(A * B(7 downto 0)), 8));
			when "11" 	=> 
				  case(B) is 
					  when x"00" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(A sll 0);
					  when x"01" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(A sll 1);
					  when x"02" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(A sll 2);
					  when x"03" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(A sll 3);
					  when x"04" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(A sll 4);
					  when x"05" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(A sll 5);
					  when x"06" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(A sll 6);
					  when x"07" 	=> ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(A sll 7);
					  when others  => ACC_DATA_IN_BUS <= STD_LOGIC_VECTOR(A sll 0);
				  end case;  
			when others => ACC_DATA_IN_BUS <= "00000000";
		end case;
	 end process ALU;

end ALU_arch;

