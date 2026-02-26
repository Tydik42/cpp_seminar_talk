#[cfg(target_os = "linux")]
const TARGET: &str = "linux";

#[cfg(not(target_os = "linux"))]
const TARGET: &str = "not-linux";

macro_rules! define_states {
    ($($state:ident),+ $(,)?) => {
        #[derive(Copy, Clone)]
        enum State {
            $($state),+
        }

        impl State {
            fn as_str(self) -> &'static str {
                match self {
                    $(State::$state => stringify!($state)),+
                }
            }
        }
    };
}

macro_rules! scoped_temp {
    ($value:expr) => {{
        let temp = $value;
        temp + 1
    }};
}

define_states!(Idle, Running, Failed);

fn main() {
    let temp = 40;
    let next = scoped_temp!(temp);
    let states = [State::Idle, State::Running, State::Failed];
    println!(
        "[rust] target={TARGET} states={}/{}/{} next={next}",
        states[0].as_str(),
        states[1].as_str(),
        states[2].as_str()
    );
}
