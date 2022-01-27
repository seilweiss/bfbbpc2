#include "zTaskBox.h"

class talk_callback : ztalkbox::callback
{
private:
	ztaskbox* task;
	ztalkbox::answer_enum answer;

public:
	talk_callback() WIP : ztalkbox::callback() {}

	virtual void on_start() STUB_VOID;
	virtual void on_stop() STUB_VOID;
	virtual void on_answer(ztalkbox::answer_enum answer) STUB_VOID;

	void reset(ztaskbox&) STUB_VOID;
};

void ztaskbox::load(const asset_type& a) STUB_VOID
void ztaskbox::read(xSerial& s) STUB_VOID
void ztaskbox::write(xSerial& s) STUB_VOID
void ztaskbox::start_talk(zNPCCommon* npc) STUB_VOID
void ztaskbox::stop_talk() STUB_VOID
void ztaskbox::enable() STUB_VOID
void ztaskbox::disable() STUB_VOID
void ztaskbox::reset() STUB_VOID
void ztaskbox::initiate() STUB_VOID
void ztaskbox::succeed() STUB_VOID
void ztaskbox::fail() STUB_VOID
void ztaskbox::complete() STUB_VOID
void ztaskbox::set_callback(callback* cb) STUB_VOID
void ztaskbox::init() STUB_VOID
void ztaskbox::load(xBase& data, xDynAsset& asset, ulong32) STUB_VOID
bool ztaskbox::exists(state_enum) STUB
void ztaskbox::set_state(state_enum state) STUB_VOID
void ztaskbox::on_talk_start() STUB_VOID
void ztaskbox::on_talk_stop(ztalkbox::answer_enum) STUB_VOID
const char* ztaskbox::get_text(uint32) STUB
bool32 ztaskbox::cb_dispatch(xBase*, xBase* to, uint32 event, const float32*, xBase*) STUB